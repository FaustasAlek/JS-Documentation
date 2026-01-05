document.addEventListener('DOMContentLoaded', () => {
    const languageSwitch = document.getElementById('language-switch');
    const initialLanguage = document.documentElement.dataset.initialLanguage || localStorage.getItem('language') || 'en';
    let currentLanguage = initialLanguage;

    function setLanguage(lang) {
        currentLanguage = lang;
        localStorage.setItem('language', lang);
        document.documentElement.lang = lang;

        document.querySelectorAll('[data-translate]').forEach(element => {
            const key = element.dataset.translate;
            const value = translations?.[lang]?.[key];

            if (value) {
                element.innerHTML = value;
            } else {
                console.warn(`Missing translation: ${lang}.${key}`);
            }
        });
    }

    if (languageSwitch) {
        languageSwitch.addEventListener('click', () => {
            setLanguage(currentLanguage === 'en' ? 'lt' : 'en');
        });
    }

    setLanguage(currentLanguage);
});
