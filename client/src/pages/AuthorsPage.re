module AuthorPreview = {
  [@react.component]
  let make = (~author: UserFragments.AuthorPreviewData.t) =>
    <div className="box">
      <p className="title is-3"> author.name->React.string </p>
    </div>;
};
[@react.component]
let make = () => {
  let authors =
    switch (UserQueries.AuthorsQuery.use()) {
    | {data: Some({authors})} => authors
    | _ => [||]
    };

  <>
    <Layout.PageTitle> "Authors"->React.string </Layout.PageTitle>
    {authors
     ->Belt.Array.map(author => <AuthorPreview key={author.id} author />)
     ->React.array}
  </>;
};
