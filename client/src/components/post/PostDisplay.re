[@react.component]
let make = (~post: PostFragments.PostDisplayData.t) => {
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
