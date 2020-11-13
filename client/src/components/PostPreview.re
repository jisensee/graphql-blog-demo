[@react.component]
let make = (~post: PostFragments.PostPreviewData.t) => {
  let authorName =
    "by "
    ++ (
      switch (post.author) {
      | Some(author) => author.name
      | None => "[deleted]"
      }
    );

  <div className="box content">
    <p className="title is-3"> post.title->React.string </p>
    <p className="subtitle is-5"> authorName->React.string </p>
    <p className="has-text-weight-semibold"> post.abstract->React.string </p>
  </div>;
};
