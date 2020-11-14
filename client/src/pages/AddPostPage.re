module Form = {
  [@react.component]
  let make = (~userId, ~loading, ~addPost) => {
    let (data, setData) =
      React.useState(() => {PostForm.title: "", content: ""});
    let onSave = _ => addPost(userId, data.title, data.content);
    let buttonClass =
      Cn.(fromList(["button", "is-success", "loading"->on(loading)]));
    let buttonDisabled = data.title === "" || data.content === "";

    <>
      <Layout.PageTitle> "Create new post"->React.string </Layout.PageTitle>
      <PostForm data onDataChange={d => setData(_ => d)}>
        <div className="field">
          <div className="control">
            <button
              className=buttonClass onClick=onSave disabled=buttonDisabled>
              <Icon icon="save" small=true />
              <span> "Save"->React.string </span>
            </button>
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
          Route.(Post(addPost.id)->navigate);
          false;
        | {loading: true} => true
        | {called: false}
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
