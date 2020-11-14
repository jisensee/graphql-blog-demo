module Query = UserQueries.UserQuery;

[@react.component]
let make = (~userId: string) => {
  let result = Query.makeVariables(~userId, ())->Query.use;
  switch (result) {
  | {data: Some({user: maybeUser})} =>
    switch (maybeUser) {
    | Some({userDisplayData: user, posts}) =>
      <>
        <div className="title is-1">
          {(user.name ++ " (@" ++ user.username ++ ")")->React.string}
        </div>
        {user.bio
         ->Belt.Option.mapWithDefault(React.null, bio =>
             <div className="box is-italic"> bio->React.string </div>
           )}
        {user.isAuthor && posts->Belt.Array.length > 0
           ? <>
               <div className="title is-3"> "Posts"->React.string </div>
               <PostPreviewList posts />
             </>
           : React.null}
      </>
    | None => <p> "That user does not exist :("->React.string </p>
    }
  | _ => React.null
  };
};
