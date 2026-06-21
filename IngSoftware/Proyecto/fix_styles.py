import re

# 1. Update style.css
with open('src/styles/style.css', 'r') as f:
    content = f.read()

# Replace body background
content = re.sub(r'body \{[\s\S]*?\}', 'body {\n  margin: 0;\n  font-family: \'Inter\', \'Segoe UI\', sans-serif;\n  background: linear-gradient(135deg, #FE8330, #FFD8B1);\n  color: #333;\n  overflow: hidden;\n}', content, count=1)

# Add glassmorphism to content-area
content = re.sub(
    r'\.content-wrapper,\s*\.content-area,\s*\.main-content,\s*\.page-container \{([\s\S]*?)\}',
    r'.content-wrapper, \n.content-area, \n.main-content,\n.page-container {\1\n  background: rgba(255, 255, 255, 0.96) !important;\n  border-radius: 24px !important;\n  box-shadow: 0 10px 30px rgba(0,0,0,0.05) !important;\n}',
    content
)
with open('src/styles/style.css', 'w') as f:
    f.write(content)

# 2. Clean specific CSS files
for css_file in ['user_home.css', 'emsa_reports.css', 'emsa_services.css', 'user_reports.css', 'citizen_reports.css']:
    try:
        with open(f'src/styles/{css_file}', 'r') as f:
            content = f.read()
        content = re.sub(r'body\s*\{[\s\S]*?\}', '', content)
        with open(f'src/styles/{css_file}', 'w') as f:
            f.write(content)
    except FileNotFoundError:
        pass

# 3. Clean HTML files
html_replacements = [
    ('user_home.html', r'<div class="main-layout" style="padding: 0; gap: 0;">', '<div class="main-layout">'),
    ('user_home.html', r'<main class="main-content" style="flex: 1; height: 100vh; overflow-y: auto; padding: 20px;">', '<main class="content-area">'),
    
    ('user_reports.html', r'<body class="citizen-theme" style="margin: 0; padding: 0;">', '<body class="citizen-theme">'),
    ('user_reports.html', r'<div class="main-layout" style="padding: 0; gap: 0;">', '<div class="main-layout">'),
    ('user_reports.html', r'<div class="page-container" style="flex: 1; height: 100vh; overflow-y: auto; padding: 25px; box-sizing: border-box;">', '<main class="content-area">'),
    ('user_reports.html', r'<main>', '<section>'),
    ('user_reports.html', r'</main>\s*</div>\s*</div>', '</section>\n    </main>\n  </div>'),

    ('emsa_reports.html', r'<body style="padding: 0;">', '<body class="emsa-theme">'),
    ('emsa_reports.html', r'<div class="main-layout" style="padding: 0; gap: 0;">', '<div class="main-layout">'),
    ('emsa_reports.html', r'<div class="page-container" style="flex: 1; height: 100vh; overflow-y: auto; padding: 40px; box-sizing: border-box;">', '<main class="content-area">'),
    ('emsa_reports.html', r'<main>', '<section>'),
    ('emsa_reports.html', r'</main>\s*</div>\s*</div>', '</section>\n    </main>\n  </div>'),

    ('user_create_report.html', r'<body class="citizen-theme" style="display: block; margin: 0; padding: 0;">', '<body class="citizen-theme">'),
    ('user_create_report.html', r'<div class="main-layout" style="padding: 0; gap: 0;">', '<div class="main-layout">'),
    ('user_create_report.html', r'<div style="flex: 1; display: flex; align-items: center; justify-content: center; height: 100vh; overflow-y: auto;">\s*<div class="app-container">', '<main class="content-area">\n      <div class="app-container" style="margin: auto;">'),
    ('user_create_report.html', r'</div>\s*</div>\s*</div>', '</div>\n    </main>\n  </div>'),

    ('index.html', r'<div class="content-wrapper">', '<main class="content-area" style="flex-direction: row !important;">'),
    ('index.html', r'<div class="card glass-card">', '<div class="form-section">'),
    ('index.html', r'</div>\s*</div>\s*<!-- NUEVO:', '</main>\n    </div>\n\n    <!-- NUEVO:')
]

for filename, old, new in html_replacements:
    try:
        with open(f'src/templates/{filename}', 'r') as f:
            content = f.read()
        content = re.sub(old, new, content)
        with open(f'src/templates/{filename}', 'w') as f:
            f.write(content)
    except FileNotFoundError:
        pass

print("Done")
