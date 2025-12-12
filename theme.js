// ===== THEME TOGGLE + BACK TO TOP + CONTACT FORM =====

const themeToggle = document.getElementById('theme-toggle');
const body = document.body;
const backToTopBtn = document.getElementById('backToTop');
const contactForm = document.getElementById('contactForm');
const contactFeedback = document.getElementById('contactFeedback');

// Lingua da página (ex. "it" ou "en")
const htmlLang = document.documentElement.lang || 'it';

// Tema salvo
const savedTheme = localStorage.getItem('theme');

// Aplica tema
function applyTheme(theme) {
  const isDark = theme === 'dark';

  body.classList.toggle('dark', isDark);
  localStorage.setItem('theme', isDark ? 'dark' : 'light');

  // Se for SWITCH (checkbox): checked = LIGHT (luz acesa)
  if (themeToggle && themeToggle.matches('input[type="checkbox"]')) {
    themeToggle.checked = !isDark;
    themeToggle.setAttribute('aria-checked', String(!isDark));
  }

  // Se for BOTÃO antigo: muda o ícone
  if (themeToggle && themeToggle.tagName === 'BUTTON') {
    themeToggle.textContent = isDark ? '☀️' : '🌙';
  }
}

// Inicializa tema
if (savedTheme === 'dark') {
  applyTheme('dark');
} else if (savedTheme === 'light') {
  applyTheme('light');
} else {
  // padrão: light
  applyTheme('light');
}

// Eventos do toggle (switch ou botão)
if (themeToggle) {
  // SWITCH
  if (themeToggle.matches('input[type="checkbox"]')) {
    themeToggle.addEventListener('change', () => {
      // checked = light, unchecked = dark
      applyTheme(themeToggle.checked ? 'light' : 'dark');
    });
  }

  // BOTÃO antigo
  if (themeToggle.tagName === 'BUTTON') {
    themeToggle.addEventListener('click', () => {
      const isCurrentlyDark = body.classList.contains('dark');
      applyTheme(isCurrentlyDark ? 'light' : 'dark');
    });
  }
}

// Botão "back to top"
if (backToTopBtn) {
  window.addEventListener('scroll', () => {
    if (window.scrollY > 300) {
      backToTopBtn.classList.add('show');
    } else {
      backToTopBtn.classList.remove('show');
    }
  });

  backToTopBtn.addEventListener('click', () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  });
}

// Form de contato: abre o email já preenchido + mensagem de feedback
if (contactForm) {
  contactForm.addEventListener('submit', (e) => {
    e.preventDefault(); // não recarrega a página

    const formData = new FormData(contactForm);
    const name = formData.get('name') || '';
    const email = formData.get('email') || '';
    const message = formData.get('message') || '';

    // Assunto do email
    const subject =
      htmlLang === 'en'
        ? `Message from portfolio – ${name}`
        : `Messaggio dal portfolio – ${name}`;

    // Corpo do email
    const bodyLines =
      htmlLang === 'en'
        ? [`Name: ${name}`, `Email: ${email}`, '', message]
        : [`Nome: ${name}`, `Email: ${email}`, '', message];

    const mailto =
      `mailto:boscaratopietro@gmail.com` +
      `?subject=${encodeURIComponent(subject)}` +
      `&body=${encodeURIComponent(bodyLines.join('\n'))}`;

    // Abre o client de email
    window.location.href = mailto;

    // Feedback
    if (contactFeedback) {
      contactFeedback.textContent =
        htmlLang === 'en'
          ? 'Thank you! Your email app should open now. If it does not, you can write me directly at boscaratopietro@gmail.com 😊'
          : 'Grazie! Il tuo programma di posta dovrebbe aprirsi ora. Se non si apre, puoi scrivermi direttamente a boscaratopietro@gmail.com 😊';
    }

    contactForm.reset();
  });
}
