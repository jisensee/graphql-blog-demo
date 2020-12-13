@react.component
let make = (~children, ~className="", ~label=?) =>
  <div className={Cn.fromList(list{className, "field"})}>
    {switch label {
    | Some(label) => <label className="label"> {label->React.string} </label>
    | None => React.null
    }}
    <div className="control"> children </div>
  </div>
