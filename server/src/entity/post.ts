import { Entity, genId, getEntityById, id } from './entity'

interface Post extends Entity {
  title: string
  content: string
  authorId: id
  createdAt: Date
}

const posts: Post[] = []

const getPosts = () => posts

const getPostsByAuthor = (authorId: id) =>
  posts.filter((p) => p.authorId === authorId)

const getPostById = (id: id) => getEntityById(posts, id)

const addPost = (authorId: id, title: string, content: string): Post => {
  const newPost: Post = {
    id: genId(),
    title,
    content,
    authorId,
    createdAt: new Date(),
  }
  posts.push(newPost)
  return newPost
}

const getPostAbstract = (post: Post) => {
  const index = post.content.indexOf('\n')
  if (index == -1) {
    return post.content
  } else {
    return post.content.slice(0, index)
  }
}

export {
  Post,
  getPosts,
  getPostsByAuthor,
  getPostById,
  addPost,
  getPostAbstract,
}
