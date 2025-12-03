const themeToggle = document.getElementById('theme-toggle');
const body = document.body;

// estado inicial: se quiser começar claro, deixa sem 'dark'
themeToggle.textContent = '🌙';

themeToggle.addEventListener('click', () => {
    body.classList.toggle('dark');

    if (body.classList.contains('dark')) {
        // modo escuro ligado -> mostra sol
        themeToggle.textContent = '☀️';
    } else {
        // modo claro -> mostra lua
        themeToggle.textContent = '🌙';
    }
});