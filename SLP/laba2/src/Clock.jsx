import React from "react";

class Clock extends React.Component {
constructor(props) {
super(props);
this.state = {
time: new Date()
};
}
componentDidMount() {
this.intervalID = setInterval(() => this.tick(), 1000);
}
componentWillUnmount() {
clearInterval(this.intervalID);
}
tick() {
this.setState({
time: new Date(),
});
}
render() {
return <p className="App-clock">The time is {this.state.time.toLocaleString('ru', {timeZone : this.props.time_zone, hour12 : this.props.hour})}.</p>
;
}
}

export default Clock;