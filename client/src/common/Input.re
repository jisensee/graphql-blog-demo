[@react.component]
let make = (~className="", ~value, ~onChange, ~valid=true, ~multiLine=false) => {
  let onValueChange = event => {
    let value: string = event->ReactEvent.Form.currentTarget##value;
    onChange(value);
  };
  let inputClassName =
    Cn.(
      fromList([
        className,
        "textarea"->on(multiLine),
        "input"->on(!multiLine),
        "is-success"->on(valid),
        "is-danger"->on(!valid),
      ])
    );

  <input className=inputClassName value onChange=onValueChange />;
};
