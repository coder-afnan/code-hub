import React from 'https://esm.sh/react@19';
import ReactDOM from 'https://esm.sh/react-dom@19/client';

const Header = () => (
    <header className="header">
        <h1>Afnan</h1>
        <p>Frontend Developer | C++ Programmer</p>
    </header>
);

const About = () => (
    <section className="about">
        <h2>About Me</h2>
        <p>
            I am a coder with a passion for creating webpges and codes. I also enjoy working on projects that challenge my problem-solving skills. I mainly code in C++ and Python.
        </p>
    </section>
);

const Skills = () => (
    <section className="skills">
        <h2>Skills</h2>
        <div className="skills-container">
            <div className="skill">HTML</div>
            <div className="skill">CSS</div>
            <div className="skill">JavaScript</div>
            <div className="skill">Python</div>
            <div className="skill">C++</div>
        </div>
    </section>
);

const Projects = () => (
    <section className="projects">
        <h2>Projects</h2>
        <div className="project">
            <h3>Portfolio Website</h3>
            <p>
                A personal website describing myself, showcasing my skills and projects.
            </p>
        </div>
        <div className="project">
            <h3>IP Tracker</h3>
            <p>
                A webpage that fetches and shows the user's IP Address along with related
                information.
            </p>
        </div>
        <div className="project">
            <h3>Message Encryptor</h3>
            <p>
                A web program that encrypts the user's message using a password.
            </p>
        </div>
        <div className="view-all-projects">
            <a href="projects.html">View All Projects</a>
        </div>
    </section>
);

const Footer = () => (
    <footer>
        <p>&copy; Afnan — All Rights Reserved.</p>
        <p>Connect with me</p>
        <div class="footer-icons">
            <div class="icon-with-label">
                <a href="https://github.com/coder-afnan"><img src="../assets/Github-logo.svg" alt="My Github" oncontextmenu="return false;" /></a>
                <p>Github</p>
            </div>
            <div class="icon-with-label">
                <a href="https://discord.gg/KKjw6U7Stw"><img src="../Discord-logo.svg" alt="My Discord Server" oncontextmenu="return false" /></a>
                <p>Discord</p>
            </div>
            <div class="icon-with-label">
                <a href="https://github.com/repo/form"><img src="../Form-logo.svg" alt="My Contact Form" oncontextmenu="return false" /></a>
                <p>Contact form</p>
            </div>
        </div>
    </footer>
);

const App = () => (
    <>
        <Header />
        <About />
        <Skills />
        <Projects />
        <Footer />
    </>
);

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<App />);
