module Comments = {
  module CommentsQuery = CommentQueries.PostCommentsQuery;
  [@react.component]
  let make = (~postId) => {
    let result = CommentsQuery.makeVariables(~postId, ())->CommentsQuery.use;
    switch (result) {
    | {data: Some({post: Some({comments})})} => <CommentList comments />
    | _ => React.null
    };
  };
};

module PostQuery = PostQueries.PostDisplayQuery;
[@react.component]
let make = (~postId: string) => {
  let result = PostQuery.makeVariables(~postId, ())->PostQuery.use;

  switch (result) {
  | {loading: true} => "Loading..."->React.string
  | {data: Some({post: maybePost})} =>
    switch (maybePost) {
    | Some(post) =>
      <>
        <PostDisplay post />
        <AddCommentForm postId={post.id} />
        <Comments postId={post.id} />
      </>
    | None => "That post does not exist :("->React.string
    }
  | {error: Some(_)}
  | _ => "Error :("->React.string
  };
};
