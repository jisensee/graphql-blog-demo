module Form = {
  [@react.component]
  let make = (~userId, ~loading, ~addPost) => {
    let (data: PostForm.data, setData) =
      React.useState(() => {PostForm.title: "", content: ""});
    let onSave = _ => addPost(userId, data.title, data.content);
    let dataValid = data.title !== "" && data.content !== "";

    <>
      <div className="title is-1"> "Create new post"->React.string </div>
      <PostForm data onDataChange={d => setData(_ => d)}>
        <div className="field">
          <div className="control">
            <Button onClick=onSave enabled=dataValid loading icon="save">
              "Save"->React.string
            </Button>
          </div>
        </div>
      </PostForm>
    </>;
  };
};

[@react.component]
let make = () => {
  let (mutate, mutationResult) = Mutations.AddPostMutation.use();
  let addPost = (authorId, title, content) =>
    mutate({authorId, title, content})->ignore;
  let (loading, setLoading) = React.useState(() => false);
  let user = UserContext.use();

  React.useEffect1(
    () => {
      let loading =
        switch (mutationResult) {
        | {data: Some({addPost})} =>
          Route.(Post(addPost.id, None)->navigate);
          false;
        | {loading: true} => true
        | _ => false
        };
      setLoading(_ => loading);
      None;
    },
    [|mutationResult|],
  );

  switch (user) {
  | Some(user) =>
    user.isAuthor
      ? <Form userId={user.id} loading addPost />
      : <p> "Sorry, you are not an author"->React.string </p>
  | None => React.null
  };
};
