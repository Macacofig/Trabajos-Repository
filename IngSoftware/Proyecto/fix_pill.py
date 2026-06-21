import re

def fix_sidebar(file_path, color_rgb):
    try:
        with open(file_path, 'r') as f:
            content = f.read()

        # Fix base sidebar
        base_regex = r'\.sidebar\.[a-z]+-theme\s*\{([\s\S]*?)\n\}'
        base_repl = f""".sidebar.{'emsa' if 'emsa' in file_path else 'citizen'}-theme {{
  /* EFECTO LIQUID GLASS PURIFICADO: 100% FLOTANTE TIPO PÍLDORA */
  background: rgba({color_rgb}, 0.15); /* Ligero tinte sobre transparente */
  color: #ffffff;
  border: 1px solid rgba(255, 255, 255, 0.2);
  border-radius: 30px;
  backdrop-filter: blur(40px);
  -webkit-backdrop-filter: blur(40px);
  box-shadow: inset 0 1px 2px rgba(255, 255, 255, 0.5), 0 20px 40px rgba(0, 0, 0, 0.2);
  width: 260px;
  min-width: 260px;
  max-width: 260px;
  height: 100%; /* Flota por el padding del grid */
  display: flex;
  flex-direction: column;
  transition: all 0.3s cubic-bezier(0.25, 1, 0.5, 1);
  position: relative;
  flex-shrink: 0;
  box-sizing: border-box;
}}"""
        content = re.sub(base_regex, base_repl, content, count=1)

        # Fix menu item
        menu_item_regex = r'\.menu-item\s*\{([\s\S]*?)\n\}'
        menu_item_repl = """.menu-item {
  display: flex;
  align-items: center;
  padding: 14px 16px;
  border-radius: 18px; /* Redondeo tipo botón */
  cursor: pointer;
  transition: all 0.3s cubic-bezier(0.25, 1, 0.5, 1);
  margin-bottom: 8px;
  opacity: 0.85;
  border: 1px solid transparent;
}"""
        content = re.sub(menu_item_regex, menu_item_repl, content, count=1)

        # Fix menu item active
        menu_active_regex = r'\.menu-item\.active\s*\{([\s\S]*?)\n\}'
        menu_active_repl = """.menu-item.active {
  font-weight: 600;
  /* Degradado luminoso tipo "pill button" de la imagen de referencia */
  background: linear-gradient(90deg, rgba(255, 255, 255, 0.25) 0%, rgba(255, 255, 255, 0.05) 100%) !important;
  opacity: 1;
  /* Borde cristalino rodeando el ítem */
  border: 1px solid rgba(255, 255, 255, 0.3);
  box-shadow: inset 0 1px 1px rgba(255, 255, 255, 0.5), 0 4px 12px rgba(0, 0, 0, 0.1);
}"""
        content = re.sub(menu_active_regex, menu_active_repl, content, count=1)

        with open(file_path, 'w') as f:
            f.write(content)
    except Exception as e:
        print(f"Failed {file_path}: {e}")

fix_sidebar('src/styles/emsa_sidebar.css', '254, 131, 48')
fix_sidebar('src/styles/citizen_sidebar.css', '18, 18, 18')

print("Done")
