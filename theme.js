const themeToggle = document.getElementById('theme-toggle');
const body = document.body;
const backToTopBtn = document.getElementById('backToTop');

// Tema salvo
const savedTheme = localStorage.getItem('theme');

if (savedTheme === 'dark') {
    body.classList.add('dark');
    if (themeToggle) themeToggle.textContent = '☀️';
} else {
    if (themeToggle) themeToggle.textContent = '🌙';
}

// Toggle tema
if (themeToggle) {
    themeToggle.addEventListener('click', () => {
        const isDark = body.classList.toggle('dark');
        if (isDark) {
            themeToggle.textContent = '☀️';
            localStorage.setItem('theme', 'dark');
        } else {
            themeToggle.textContent = '🌙';
            localStorage.setItem('theme', 'light');
        }
    });
}

// Botão voltar ao topo
if (backToTopBtn) {
    window.addEventListener('scroll', () => {
        if (window.scrollY > 300) {
            backToTopBtn.classList.add('show');
        } else {
            backToTopBtn.classList.remove('show');
        }
    });

    backToTopBtn.addEventListener('click', () => {
        window.scrollTo({
            top: 0,
            behavior: 'smooth'
        });
    });
}
