// ===== THEME TOGGLE + BACK TO TOP + CONTACT FORM =====

const themeToggle = document.getElementById('theme-toggle');
const body = document.body;
const backToTopBtn = document.getElementById('backToTop');
const contactForm = document.getElementById('contactForm');
const contactFeedback = document.getElementById('contactFeedback');

const htmlLang = document.documentElement.lang || 'it';

function setTheme(theme) {
  const isDark = theme === 'dark';
  body.classList.toggle('dark', isDark);
  localStorage.setItem('theme', isDark ? 'dark' : 'light');

  // Se for SWITCH: checked = LIGHT (luz acesa)
  if (themeToggle && themeToggle.matches('input[type="checkbox"]')) {
    themeToggle.checked = !isDark;
    themeToggle.setAttribute('aria-checked', String(!isDark));
  }

  // Se for BOTÃO antigo: troca o ícone
  if (themeToggle && themeToggle.tagName === 'BUTTON') {
    themeToggle.textContent = isDark ? '☀️' : '🌙';
  }
}

// Inicializa tema
const savedTheme = localStorage.getItem('theme');
if (savedTheme === 'dark') setTheme('dark');
else setTheme('light');

// Evento do toggle
if (themeToggle) {
  // SWITCH (checkbox)
  if (themeToggle.matches('input[type="checkbox"]')) {
    themeToggle.addEventListener('change', () => {
      // checked = light, unchecked = dark
      setTheme(themeToggle.checked ? 'light' : 'dark');
    });
  }

  // BOTÃO antigo
  if (themeToggle.tagName === 'BUTTON') {
    themeToggle.addEventListener('click', () => {
      const isDarkNow = body.classList.contains('dark');
      setTheme(isDarkNow ? 'light' : 'dark');
    });
  }
}

// Back to top
if (backToTopBtn) {
  window.addEventListener('scroll', () => {
    backToTopBtn.classList.toggle('show', window.scrollY > 300);
  });

  backToTopBtn.addEventListener('click', () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  });
}

// Contact form (mailto)
if (contactForm) {
  contactForm.addEventListener('submit', (e) => {
    e.preventDefault();

    const formData = new FormData(contactForm);
    const name = formData.get('name') || '';
    const email = formData.get('email') || '';
    const message = formData.get('message') || '';

    const subject =
      htmlLang === 'en'
        ? `Message from portfolio – ${name}`
        : `Messaggio dal portfolio – ${name}`;

    const bodyLines =
      htmlLang === 'en'
        ? [`Name: ${name}`, `Email: ${email}`, '', message]
        : [`Nome: ${name}`, `Email: ${email}`, '', message];

    const mailto =
      `mailto:boscaratopietro@gmail.com` +
      `?subject=${encodeURIComponent(subject)}` +
      `&body=${encodeURIComponent(bodyLines.join('\n'))}`;

    window.location.href = mailto;

    if (contactFeedback) {
      contactFeedback.textContent =
        htmlLang === 'en'
          ? 'Thank you! Your email app should open now. If it does not, you can write me directly at boscaratopietro@gmail.com 😊'
          : 'Grazie! Il tuo programma di posta dovrebbe aprirsi ora. Se non si apre, puoi scrivermi direttamente a boscaratopietro@gmail.com 😊';
    }

    contactForm.reset();
  });
}
