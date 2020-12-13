@react.component
let make = (~to_, ~children, ~onClick=() => (), ~className="") => {
  let href = to_->Route.toString
  let onClick = event => {
    event->ReactEvent.Mouse.preventDefault
    href->ReasonReactRouter.push
    onClick()
  }
  <a href className onClick> children </a>
}
