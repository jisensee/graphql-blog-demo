module Display = {
  @react.component
  let make = (~className="", ~of_) =>
    <span className> {Js.Date.fromString(of_)->Js.Date.toLocaleString->React.string} </span>
}

let compare = (ts1, ts2) => {
  let toEpoch = ts => ts->Js.Date.fromString->Js.Date.getTime
  compare(ts1->toEpoch, ts2->toEpoch)
}
