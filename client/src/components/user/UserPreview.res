@react.component
let make = (~user: UserFragments.UserPreviewData.t) =>
  <div className="box context">
    <Link className="title is-3" to_=Route.User(user.id)> {user.name->React.string} </Link>
    <p className="is-italic"> {user.bio->Belt.Option.getWithDefault("")->React.string} </p>
    <p> {("Posts: " ++ string_of_int(user.postCount))->React.string} </p>
  </div>
