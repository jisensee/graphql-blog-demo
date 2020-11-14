type id = string;
type postId = string;
type userId = string;
type commentId = string;

type t =
  | Posts
  | Post(postId, option(commentId))
  | AddPost
  | Authors
  | User(userId)
  | NotFound;

let toString =
  fun
  | Posts => "/"
  | AddPost => "/post/add"
  | Post(postId, None) => "/post/" ++ postId
  | Post(postId, Some(commentId)) => "/post/" ++ postId ++ "#" ++ commentId
  | Authors => "/authors"
  | User(userId) => "/user/" ++ userId
  | NotFound => "/404";

let fromUrl = (url: ReasonReactRouter.url) =>
  switch (url) {
  | {path: []}
  | {path: ["/"]} => Posts
  | {path: ["post", "add"]} => AddPost
  | {path: ["post", postId], hash: commentId} when commentId !== "" =>
    Post(postId, Some(commentId))
  | {path: ["post", postId]} => Post(postId, None)
  | {path: ["user", userId]} => User(userId)
  | {path: ["authors"]} => Authors
  | _ => NotFound
  };

let navigate = route => route->toString->ReasonReactRouter.push;
