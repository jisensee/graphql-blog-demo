type id = string
type postId = string
type userId = string
type commentId = string

type t =
  | Posts
  | Post(postId, option<commentId>)
  | AddPost
  | Authors
  | User(userId)
  | NotFound

let toString = x =>
  switch x {
  | Posts => "/"
  | AddPost => "/post/add"
  | Post(postId, None) => "/post/" ++ postId
  | Post(postId, Some(commentId)) => "/post/" ++ (postId ++ ("#" ++ commentId))
  | Authors => "/authors"
  | User(userId) => "/user/" ++ userId
  | NotFound => "/404"
  }

let fromUrl = (url: ReasonReactRouter.url) =>
  switch url {
  | {path: list{}}
  | {path: list{"/"}} =>
    Posts
  | {path: list{"post", "add"}} => AddPost
  | {path: list{"post", postId}, hash: commentId} when commentId !== "" =>
    Post(postId, Some(commentId))
  | {path: list{"post", postId}} => Post(postId, None)
  | {path: list{"user", userId}} => User(userId)
  | {path: list{"authors"}} => Authors
  | _ => NotFound
  }

let navigate = route => route->toString->ReasonReactRouter.push
