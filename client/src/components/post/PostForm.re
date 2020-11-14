type data = {
  title: string,
  content: string,
};

[@react.component]
let make = (~children=?, ~data, ~onDataChange) => {
  let onTitleChange = event => {
    let value = event->ReactEvent.Form.currentTarget##value;
    onDataChange({...data, title: value});
  };
  let onContentChange = event => {
    let value = event->ReactEvent.Form.currentTarget##value;
    onDataChange({...data, content: value});
  };
  let getInputClass = (className, valid) =>
    Cn.(
      fromList([
        className,
        "is-success"->on(valid),
        "is-danger"->on(!valid),
      ])
    );
  let titleInputClass = getInputClass("input", data.title !== "");
  let contentInputClass = getInputClass("textarea", data.content !== "");

  <form>
    <div className="field">
      <label className="label"> "Title"->React.string </label>
      <div className="control">
        <input
          className=titleInputClass
          value={data.title}
          onChange=onTitleChange
        />
      </div>
    </div>
    <div className="field">
      <label className="label"> "Content"->React.string </label>
      <div className="control">
        <textarea
          className=contentInputClass
          value={data.content}
          onChange=onContentChange
        />
      </div>
    </div>
    {children->Belt.Option.getWithDefault(React.null)}
  </form>;
};
