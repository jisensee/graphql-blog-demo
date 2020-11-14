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

  <> <div className="title is-1"> "Posts"->React.string </div> content </>;
};
