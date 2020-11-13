open PostQueries;
open PostFragments;

module PostDisplay = {
  [@react.component]
  let make = (~post: PostDisplayData.t) => {
    let contentStyle = ReactDOM.Style.make(~whiteSpace="pre-wrap", ());
    let authorName =
      <UserRef
        userData={
          post.author
          ->Belt.Option.map(user => {UserRef.id: user.id, name: user.name})
        }
      />;
    <>
      <Layout.PageTitle> post.title->React.string </Layout.PageTitle>
      <Layout.PageSubTitle>
        <span> "By "->React.string </span>
        authorName
      </Layout.PageSubTitle>
      <div className="content" style=contentStyle>
        post.content->React.string
      </div>
    </>;
  };
};

[@react.component]
let make = (~postId: string) => {
  let vars =
    PostDisplayQuery.PostDisplayQuery_inner.makeVariables(~postId, ());
  switch (PostDisplayQuery.use(vars)) {
  | {loading: true} => "Loading..."->React.string
  | {data: Some({post: maybePost})} =>
    switch (maybePost) {
    | Some(post) => <PostDisplay post />
    | None => "That post does not exist :("->React.string
    }
  | {error: Some(_)}
  | _ => "Error :("->React.string
  };
};
