import sys
import os

def upscale_line(line, scale):
    return ''.join(char * scale for char in line)

def upscale_xpm(xpm_lines, scale):
    header = xpm_lines[0].split()
    old_width = int(header[0])
    old_height = int(header[1])
    num_colors = int(header[2])
    chars_per_pixel = int(header[3])

    new_width = old_width * scale
    new_height = old_height * scale
    header[0] = str(new_width)
    header[1] = str(new_height)

    new_xpm = [' '.join(header)]
    # Copiamos todas las líneas de definición de colores
    new_xpm += xpm_lines[1:1 + num_colors]

    pixels = xpm_lines[1 + num_colors:]
    for line in pixels:
        up_line = upscale_line(line, scale)
        for _ in range(scale):
            new_xpm.append(up_line)

    return new_xpm

def main():
    if len(sys.argv) < 2:
        print("❌ Uso: python upscale_xpm.py archivo.xpm [factor]")
        sys.exit(1)

    input_file = sys.argv[1]
    scale_factor = int(sys.argv[2]) if len(sys.argv) > 2 else 4

    if not os.path.isfile(input_file):
        print(f"❌ Archivo no encontrado: {input_file}")
        sys.exit(1)

    with open(input_file, "r") as f:
        lines = []
        for line in f:
            line = line.strip()
            if not line or line.startswith("/*") or line.startswith("static") or line.startswith("};"):
                continue
            # Quitar comillas y coma solo si están en el formato estándar
            if line.startswith('"') and line.endswith('",'):
                line = line[1:-2]
            elif line.startswith('"') and line.endswith('"'):
                line = line[1:-1]
            lines.append(line)

    result = upscale_xpm(lines, scale_factor)

    base_name, ext = os.path.splitext(input_file)
    output_file = f"../output/{base_name}.xpm"

    with open(output_file, "w") as f:
        f.write("/* XPM */\n")
        f.write("static char *upscaled[] = {\n")
        for line in result[:-1]:
            f.write(f'"{line}",\n')  # con coma
        f.write(f'"{result[-1]}"\n')  # última línea sin coma
        f.write("};\n")

    print(f"✅ XPM escalado guardado en: {output_file}")

if __name__ == "__main__":
    main()
