open PostQueries;

[@react.component]
let make = () => {
  let content =
    switch (PostPreviewsQuery.use()) {
    | {loading: true} => "Loading..."->React.string
    | {data: Some({posts})} => <PostPreviewList posts />
    | {error: Some(_)}
    | _ => "Could not load posts :("->React.string
    };

  <> <Layout.PageTitle> "Posts"->React.string </Layout.PageTitle> content </>;
};
