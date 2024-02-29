import React, { useState } from 'react';
import './App.css';
import Menu from './Menu/Menu';

const App = () => {
  const [menuActive, setMenuActive] = useState(false)
  const items = [
    {value: "Программист", href: "https://www.codecademy.com", icon: "P"},
    {value: "Дизайнер", href: "https://www.kp.ru/putevoditel/obrazovanie/dizajner/", icon: "D"},
    {value: "Водитель", href: "https://www.gazu.ru/driving/for_beginners/", icon: "V"},
    {value: "Актер", href: "https://proektoria.online/catalog/professions/aktyor", icon: "A"},
    {value: "Нефтяник", href: "https://moeobrazovanie.ru/professions_neftyanik.html", icon: "N"},
]
  return (
    <div className='app'>
      <nav>
        <div className='JobMenu' onClick={() => setMenuActive(!menuActive)}>
          <span/>
          </div>
      </nav>
      <main>
        <p>Текст Текст Текст Текст Текст Текст Текст Текст Текст Текст</p>
        <p>Текст Текст Текст Текст Текст Текст Текст Текст Текст Текст</p>
        <p>Текст Текст Текст Текст Текст Текст Текст Текст Текст Текст</p>
        <p>Текст Текст Текст Текст Текст Текст Текст Текст Текст Текст</p>
        <p>Текст Текст Текст Текст Текст Текст Текст Текст Текст Текст</p>
      </main>
      <Menu active={menuActive} setActive={setMenuActive} header={'Профессии:'} items={items}/>
      </div>    
  );
};

export default App;