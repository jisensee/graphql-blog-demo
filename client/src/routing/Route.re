type t =
  | Posts
  | Post(string)
  | AddPost
  | Authors
  | NotFound;

let toString =
  fun
  | Posts => "/"
  | Post(postId) => "/post/" ++ postId
  | AddPost => "/post/add"
  | Authors => "/authors"
  | NotFound => "/404";

let fromPath =
  fun
  | []
  | ["/"] => Posts
  | ["post", "add"] => AddPost
  | ["post", postId] => Post(postId)
  | ["authors"] => Authors
  | _ => NotFound;

let navigate = route => route->toString->ReasonReactRouter.push;
