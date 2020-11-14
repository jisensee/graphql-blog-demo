type data = {
  title: string,
  content: string,
};

[@react.component]
let make = (~children=?, ~data, ~onDataChange) => {
  let onTitleChange = value => onDataChange({...data, title: value});
  let onContentChange = value => onDataChange({...data, content: value});

  <form>
    <FormField label="Title">
      <Input
        value={data.title}
        onChange=onTitleChange
        valid={data.title !== ""}
      />
    </FormField>
    <FormField label="Content">
      <Input
        multiLine=true
        value={data.content}
        onChange=onContentChange
        valid={data.content !== ""}
      />
    </FormField>
    {children->Belt.Option.getWithDefault(React.null)}
  </form>;
};
