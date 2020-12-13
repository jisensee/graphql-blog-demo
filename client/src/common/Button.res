type style =
  | Info
  | Success

@react.component
let make = (
  ~children,
  ~onClick,
  ~className="",
  ~loading=false,
  ~enabled=true,
  ~icon=?,
  ~style=Info,
) => {
  let cn = {
    open Cn
    fromList(list{
      className,
      "button",
      "is-loading"->on(loading),
      switch style {
      | Info => "is-info"
      | Success => "is-sucess"
      },
    })
  }
  let onButtonClick = event => {
    event->ReactEvent.Mouse.preventDefault
    onClick(event)
  }
  <button className=cn onClick=onButtonClick disabled={!enabled}>
    {switch icon {
    | Some(icon) => <Icon icon small=true />
    | None => React.null
    }}
    <span> children </span>
  </button>
}
