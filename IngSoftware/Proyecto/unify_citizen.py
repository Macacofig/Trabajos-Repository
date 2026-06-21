import re

# 1. Update style.css with the new unified classes
with open('src/styles/style.css', 'r') as f:
    style_content = f.read()

new_classes = """
/* ==============================================
   DISEÑO UNIFICADO DE PÁGINAS (PREMIUM GLASS)
   ============================================== */
.page-header {
  background: rgba(18, 18, 18, 0.7);
  backdrop-filter: blur(30px);
  -webkit-backdrop-filter: blur(30px);
  border-radius: 24px;
  padding: 25px 35px;
  color: #ffffff;
  margin-bottom: 25px;
  border: 1px solid rgba(255, 255, 255, 0.15);
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
}

.page-header h1 {
  margin: 0;
  font-size: 2.2rem;
  font-weight: 600;
  letter-spacing: 1px;
}

.page-header p {
  margin: 8px 0 0 0;
  opacity: 0.85;
  font-size: 15px;
}

.glass-container {
  background: rgba(255, 255, 255, 0.92);
  backdrop-filter: blur(25px);
  -webkit-backdrop-filter: blur(25px);
  border-radius: 24px;
  padding: 30px;
  border: 1px solid rgba(255, 255, 255, 0.4);
  box-shadow: 0 15px 35px rgba(0, 0, 0, 0.1);
  color: #333333;
  margin-bottom: 20px;
}

/* Eliminar viejos estilos del titulo gigante de user_home.css si quedan en style.css */
"""

if "DISEÑO UNIFICADO DE PÁGINAS" not in style_content:
    style_content += new_classes
    with open('src/styles/style.css', 'w') as f:
        f.write(style_content)


# 2. Refactor user_home.html
with open('src/templates/user_home.html', 'r') as f:
    user_home = f.read()

# Replace header
user_home = re.sub(
    r'<header class="main-header">[\s\S]*?</header>',
    """<header class="page-header">
                <h1>Rutas y Horarios</h1>
                <p>Encuentra las rutas de recolección de basura en tu zona</p>
            </header>""",
    user_home
)
# Wrap filters and cards in glass-container
user_home = re.sub(
    r'<section class="filters">',
    """<div class="glass-container">\n            <section class="filters">""",
    user_home
)
user_home = re.sub(
    r'</section>\s*<!-- GRILLA DE RUTAS -->',
    r'</section>\n\n            <!-- GRILLA DE RUTAS -->',
    user_home
)
user_home = re.sub(
    r'</section>\s*</main>',
    r'</section>\n            </div>\n        </main>',
    user_home
)

with open('src/templates/user_home.html', 'w') as f:
    f.write(user_home)


# 3. Refactor user_reports.html
with open('src/templates/user_reports.html', 'r') as f:
    user_rep = f.read()

user_rep = re.sub(
    r'<header class="topbar">[\s\S]*?</header>',
    """<header class="page-header">
        <h1>Mis Reportes</h1>
        <p>Historial de incidencias registradas</p>
      </header>""",
    user_rep
)

user_rep = re.sub(
    r'<section class="filters-section">',
    """<div class="glass-container" style="display: flex; flex-direction: column; gap: 20px;">\n      <section class="filters-section">""",
    user_rep
)

user_rep = re.sub(
    r'</main>',
    r'</div>\n    </main>',
    user_rep
)

# En citizen_reports.css, quitar background de .filters-container y padding excesivo, ya que ahora lo hereda de glass-container
with open('src/styles/citizen_reports.css', 'r') as f:
    cit_css = f.read()

cit_css = re.sub(r'background:[\s\S]*?rgba\(255, 255, 255, 0.15\);', '/* background rem */', cit_css)
cit_css = re.sub(r'backdrop-filter: blur\(20px\);', '', cit_css)
with open('src/styles/citizen_reports.css', 'w') as f:
    f.write(cit_css)

with open('src/templates/user_reports.html', 'w') as f:
    f.write(user_rep)


# 4. Refactor user_create_report.html
with open('src/templates/user_create_report.html', 'r') as f:
    user_create = f.read()

user_create = re.sub(
    r'<div class="info-panel">[\s\S]*?</div>',
    """<header class="page-header" style="width: 100%; box-sizing: border-box; margin-bottom: 20px;">
          <h1>Crear Reporte</h1>
          <p>Completa los datos para generar un reporte ciudadano de forma rápida y sencilla.</p>
        </header>""",
    user_create
)
# Change the container layout from flex row to standard vertical flowing layout
user_create = re.sub(
    r'<div class="app-container" style="margin: auto;">',
    r'<div class="app-container" style="display: flex; flex-direction: column; width: 100%; max-width: 100%; height: auto;">',
    user_create
)

user_create = re.sub(
    r'<div class="form-panel">',
    r'<div class="form-panel glass-container" style="width: 100%; box-sizing: border-box; box-shadow: none;">',
    user_create
)

with open('src/templates/user_create_report.html', 'w') as f:
    f.write(user_create)


print("Done")
