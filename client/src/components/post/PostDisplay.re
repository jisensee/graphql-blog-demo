[@react.component]
let make = (~post: PostFragments.PostDisplayData.t) => {
  let contentStyle = ReactDOM.Style.make(~whiteSpace="pre-wrap", ());
  let user = UserContext.use();
  let (mutate, mutationResult) = Mutations.LikePostMutation.use();
  let likePost = () => {
    switch (user) {
    | None => ()
    | Some({id}) => mutate({postId: post.id, userId: id})->ignore
    };
  };

  let likes =
    switch (mutationResult) {
    | {data: Some({likePost: Some(likes)})} => likes
    | _ => post.likes
    };

  let authorName =
    <UserRef
      userData={
        post.author
        ->Belt.Option.map(user => {UserRef.id: user.id, name: user.name})
      }
    />;
  <>
    <div className="title is-1"> post.title->React.string </div>
    <span className="subtitle is-4">
      <span> "By "->React.string </span>
      authorName
    </span>
    <Timestamp.Display className="is-italic ml-2" of_={post.createdAt} />
    <a onClick={_ => likePost()}>
      <p> <Icon icon="thumbs-up"> likes->React.int </Icon> </p>
    </a>
    <p className="content mt-3" style=contentStyle>
      post.content->React.string
    </p>
  </>;
};
