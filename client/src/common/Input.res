@react.component
let make = (~className="", ~value, ~onChange, ~placeholder="", ~valid=true, ~multiLine=false) => {
  let onValueChange = event => {
    let value: string = (event->ReactEvent.Form.currentTarget)["value"]
    onChange(value)
  }
  let inputClassName = {
    open Cn
    fromList(list{
      className,
      "textarea"->on(multiLine),
      "input"->on(!multiLine),
      "is-success"->on(valid),
      "is-danger"->on(!valid),
    })
  }

  multiLine
    ? <textarea className=inputClassName value onChange=onValueChange placeholder />
    : <input className=inputClassName value onChange=onValueChange placeholder />
}
