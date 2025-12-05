const themeToggle = document.getElementById('theme-toggle');
const body = document.body;

// Verifica tema salvo no localStorage ao carregar a página
const savedTheme = localStorage.getItem('theme');

if (savedTheme === 'dark') {
    body.classList.add('dark');
    themeToggle.textContent = '☀️'; // já começa no escuro, mostra sol
} else {
    themeToggle.textContent = '🌙'; // padrão: claro, mostra lua
}

// Alterna tema ao clicar no botão
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
