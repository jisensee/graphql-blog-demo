[@react.component]
let make =
    (
      ~children,
      ~onClick,
      ~className="",
      ~loading=false,
      ~enabled=true,
      ~icon=?,
    ) => {
  let cn =
    Cn.(
      fromList([
        className,
        "button",
        "is-success",
        "is-loading"->on(loading),
      ])
    );
  let onButtonClick = event => {
    event->ReactEvent.Mouse.preventDefault;
    onClick(event);
  };
  <button className=cn onClick=onButtonClick disabled={!enabled}>
    {switch (icon) {
     | Some(icon) => <Icon icon small=true />
     | None => React.null
     }}
    <span> children </span>
  </button>;
};
