open Belt;
open PostQueries;
open PostFragments;

module PostList = {
  [@react.component]
  let make = (~posts: array(PostPreviewData.t)) =>
    posts
    ->Array.map(post =>
        <Link key={post.id} to_={Route.Post(post.id)}>
          <PostPreview post />
        </Link>
      )
    ->React.array;
};

[@react.component]
let make = () => {
  let content =
    switch (PostPreviewsQuery.use()) {
    | {loading: true} => "Loading..."->React.string
    | {data: Some({posts})} => <PostList posts />
    | {error: Some(_)}
    | _ => "Could not load posts :("->React.string
    };

  <> <Layout.PageTitle> "Posts"->React.string </Layout.PageTitle> content </>;
};
