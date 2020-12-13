@react.component
let make = (~icon, ~small=false, ~children=?) => {
  let iconElement =
    <span
      className={
        open Cn
        fromList(list{"icon", "is-small"->on(small), "is-medium"->on(!small)})
      }>
      <i className={"fas fa-lg fa-" ++ icon} />
    </span>
  switch children {
  | None => iconElement
  | Some(text) =>
    <div className="columns is-vcentered is-mobile">
      <div className="column is-narrow pr-0"> iconElement </div>
      <div className="column is-narrow pl-1"> text </div>
    </div>
  }
}
