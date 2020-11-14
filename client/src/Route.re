type id = string;

type t =
  | Posts
  | Post(id)
  | AddPost
  | Authors
  | User(id)
  | NotFound;

let toString =
  fun
  | Posts => "/"
  | AddPost => "/post/add"
  | Post(postId) => "/post/" ++ postId
  | Authors => "/authors"
  | User(userId) => "/user/" ++ userId
  | NotFound => "/404";

let fromPath =
  fun
  | []
  | ["/"] => Posts
  | ["post", "add"] => AddPost
  | ["post", postId] => Post(postId)
  | ["user", userId] => User(userId)
  | ["authors"] => Authors
  | _ => NotFound;

let navigate = route => route->toString->ReasonReactRouter.push;
