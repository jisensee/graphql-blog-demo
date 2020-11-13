type t =
  | Posts
  | Post(string)
  | Authors
  | NotFound;

let toString =
  fun
  | Posts => "/"
  | Post(postId) => "/post/" ++ postId
  | Authors => "/authors"
  | NotFound => "/404";

let fromPath =
  fun
  | []
  | ["/"] => Posts
  | ["post", postId] => Post(postId)
  | ["authors"] => Authors
  | _ => NotFound;
