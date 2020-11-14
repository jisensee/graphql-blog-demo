type data = {
  title: string,
  content: string,
};

[@react.component]
let make = (~data, ~onDataChange) => {
  let onTitleChange = event => {
    let value = event->ReactEvent.Form.currentTarget##value;
    onDataChange({...data, title: value});
  };
  let onContentChange = event => {
    let value = event->ReactEvent.Form.currentTarget##value;
    onDataChange({...data, content: value});
  };

  <form>
    <div className="field">
      <label className="label"> "Title"->React.string </label>
      <div className="control">
        <input className="input" value={data.title} onChange=onTitleChange />
      </div>
    </div>
    <div className="field">
      <label className="label"> "Content"->React.string </label>
      <div className="control">
        <textarea
          className="textarea"
          value={data.content}
          onChange=onContentChange
        />
      </div>
    </div>
  </form>;
};
