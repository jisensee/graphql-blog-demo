[@react.component]
let make = (~icon, ~children=?) => {
  let iconElement =
    <span className="icon is-medium">
      <i className={"fas fa-lg fa-" ++ icon} />
    </span>;
  switch (children) {
  | None => iconElement
  | Some(text) =>
    <div className="columns is-vcentered is-mobile">
      <div className="column is-narrow pr-0"> iconElement </div>
      <div className="column is-narrow pl-1"> text </div>
    </div>
  };
};
