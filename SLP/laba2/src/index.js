import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import Clock from './Clock';

Clock.defaultProps = {time_zone: "Europe/London", hour : true}

ReactDOM.render(
  <React.StrictMode>
      <App />
      <Clock />
  </React.StrictMode>,
document.getElementById('root')
);
