import { Entity, genId, id } from './entity'

interface Comment extends Entity {
  content: string
  createdAt: Date
  authorId: id
  postId: id
}

const comments: Comment[] = []

const getCommentsByPost = (postId: id) =>
  comments.filter((c) => c.postId === postId)

const getCommentsByUser = (userId: id) =>
  comments.filter((c) => c.authorId === userId)

const addComment = (authorId: id, postId: id, content: string) => {
  const newComment: Comment = {
    id: genId(),
    content,
    createdAt: new Date(),
    authorId,
    postId,
  }
  comments.push(newComment)
  return newComment
}

export { Comment, getCommentsByPost, getCommentsByUser, addComment }
