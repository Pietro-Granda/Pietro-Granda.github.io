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

    if (themeToggle && themeToggle.matches('input[type="checkbox"]')) {
        themeToggle.checked = !isDark;
        themeToggle.setAttribute('aria-checked', String(!isDark));
    }
}

const savedTheme = localStorage.getItem('theme');
if (savedTheme === 'dark') setTheme('dark');
else setTheme('light');

if (themeToggle) {
    if (themeToggle.matches('input[type="checkbox"]')) {
        themeToggle.addEventListener('change', () => {
            setTheme(themeToggle.checked ? 'light' : 'dark');
        });
    }

    if (themeToggle.tagName === 'BUTTON') {
        themeToggle.addEventListener('click', () => {
            const isDarkNow = body.classList.contains('dark');
            setTheme(isDarkNow ? 'light' : 'dark');
        });
    }
}

if (backToTopBtn) {
    window.addEventListener('scroll', () => {
        backToTopBtn.classList.toggle('show', window.scrollY > 300);
    });

    backToTopBtn.addEventListener('click', () => {
        window.scrollTo({ top: 0, behavior: 'smooth' });
    });
}

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


const container = document.querySelector('.floating-shapes');
const numShapes = 30;
const shapes = [
    '💻', '👨🏻‍💻', '👾', '</>', '🤖', '{ }', '🖥️',
    '/img/svg/github.svg', '/img/svg/js.svg',
    '/img/svg/c.svg', '/img/svg/c++.svg', '/img/svg/java.svg',
    '/img/svg/css.svg', '/img/svg/html.svg', '/img/svg/vscode.svg',
    '/img/svg/unity.svg'
];

const floatingObjects = [];
for (let i = 0; i < numShapes; i++) {
    const item = shapes[Math.floor(Math.random() * shapes.length)];
    let shape;

    if (item.endsWith('.svg')) {
        shape = document.createElement('img');
        shape.src = item;
        shape.style.width = shape.style.height = `${12 + Math.random() * 20}px`;
    } else {
        shape = document.createElement('span');
        shape.textContent = item;
        shape.style.fontSize = `${12 + Math.random() * 20}px`;
    }
    shape.classList.add('shape');

    let x = Math.random() * window.innerWidth;
    let y = Math.random() * window.innerHeight;
    let z = Math.random();
    let vx = (Math.random() - 0.5) * 0.2 * (1 + z);
    let vy = (Math.random() - 0.5) * 0.2 * (1 + z);
    shape.style.opacity = 0.3 + z * 0.7;

    container.appendChild(shape);
    floatingObjects.push({ shape, x, y, z, vx, vy });
}

function animate() {
    floatingObjects.forEach(obj => {
        obj.x += obj.vx;
        obj.y += obj.vy;

        // Rimbalzo ai bordi
        if (obj.x < -10 || obj.x > window.innerWidth + 10) obj.vx *= -1;
        if (obj.y < -10 || obj.y > window.innerHeight + 10) obj.vy *= -1;

        obj.shape.style.transform = `translate3d(${obj.x}px, ${obj.y}px, 0)`;
    });

    requestAnimationFrame(animate);
}

animate();

window.addEventListener('resize', () => {
    floatingObjects.forEach(obj => {
        if (obj.x > window.innerWidth) obj.x = window.innerWidth * Math.random();
        if (obj.y > window.innerHeight) obj.y = window.innerHeight * Math.random();
    });
});