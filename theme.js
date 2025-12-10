const themeToggle = document.getElementById('theme-toggle');
const body = document.body;
const backToTopBtn = document.getElementById('backToTop');
const contactForm = document.getElementById('contactForm');
const contactFeedback = document.getElementById('contactFeedback');

// Lingua della pagina (es. "it" o "en")
const htmlLang = document.documentElement.lang || 'it';

// Tema salvato
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

// Bottone "back to top"
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

// Form di contatto: apre l'email già compilata + messaggio di conferma
if (contactForm) {
    contactForm.addEventListener('submit', (e) => {
        e.preventDefault(); // non ricarica la pagina

        const formData = new FormData(contactForm);
        const name = formData.get('name') || '';
        const email = formData.get('email') || '';
        const message = formData.get('message') || '';

        // Oggetto dell'email
        const subject = (htmlLang === 'en')
            ? `Message from portfolio – ${name}`
            : `Messaggio dal portfolio – ${name}`;

        // Corpo dell'email
        const bodyLines = (htmlLang === 'en')
            ? [
                `Name: ${name}`,
                `Email: ${email}`,
                '',
                message
              ]
            : [
                `Nome: ${name}`,
                `Email: ${email}`,
                '',
                message
              ];

        const mailto = `mailto:boscaratopietro@gmail.com` +
                       `?subject=${encodeURIComponent(subject)}` +
                       `&body=${encodeURIComponent(bodyLines.join('\n'))}`;

        // apre il client di posta
        window.location.href = mailto;

        // Messaggio di feedback sotto al form
        if (contactFeedback) {
            contactFeedback.textContent = (htmlLang === 'en')
                ? 'Thank you! Your email app should open now. If it does not, you can write me directly at boscaratopietro@gmail.com 😊'
                : 'Grazie! Il tuo programma di posta dovrebbe aprirsi ora. Se non si apre, puoi scrivermi direttamente a boscaratopietro@gmail.com 😊';
        }

        contactForm.reset();
    });
}