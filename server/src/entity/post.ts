import { Entity, genId, getEntityById, id } from './entity'

interface Post extends Entity {
  title: string
  content: string
  authorId: id
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
  }
  posts.push(newPost)
  return newPost
}

export { Post, getPosts, getPostsByAuthor, getPostById, addPost }
