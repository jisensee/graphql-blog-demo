module Form = {
  [@react.component]
  let make = (~userId, ~postId, ~loading, ~addComment) => {
    let (content, setContent) = React.useState(() => "");
    let onSave = _ => {
      addComment(userId, postId, content);
      setContent(_ => "");
    };
    let contentValid = content !== "";

    <form>
      <FormField>
        <Input
          value=content
          onChange={value => setContent(_ => value)}
          valid=contentValid
          placeholder="Say something nice!"
        />
      </FormField>
      <FormField>
        <Button
          onClick=onSave
          enabled={contentValid && !loading}
          icon="save"
          loading>
          "Save"->React.string
        </Button>
      </FormField>
    </form>;
  };
};
[@react.component]
let make = (~postId) => {
  let (mutate, mutationResult) = Mutations.AddCommentMutation.use();
  let addComment = (authorId, postId, content) =>
    mutate(
      ~refetchQueries=[|
        CommentQueries.PostCommentsQuery.(
          refetchQueryDescription(makeVariables(~postId, ()))
        ),
      |],
      {authorId, postId, content},
    )
    ->ignore;
  let (loading, setLoading) = React.useState(() => false);
  let user = UserContext.use();

  React.useEffect1(
    () => {
      let loading =
        switch (mutationResult) {
        | {data: Some(_)} => false
        | {loading: true} => true
        | _ => false
        };
      setLoading(_ => loading);
      None;
    },
    [|mutationResult|],
  );

  switch (user) {
  | Some({id: userId}) => <Form userId postId loading addComment />
  | None => React.null
  };
};
