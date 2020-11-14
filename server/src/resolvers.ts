import { IResolvers } from 'graphql-tools'
import {
  addComment,
  Comment,
  getCommentsByPost,
  getCommentsByUser,
} from './entity/comment'
import {
  addPost,
  getPostAbstract,
  getPostById,
  getPosts,
  getPostsByAuthor,
  Post,
} from './entity/post'
import { getAuthors, getUserById, getUsers, User } from './entity/user'

const resolvers: IResolvers = {
  Query: {
    users: () => getUsers(),
    authors: () => getAuthors(),
    user: (_, args) => getUserById(args.id),

    posts: () => getPosts(),
    post: (_, args) => getPostById(args.id),
  },
  Mutation: {
    addPost: (_, args) => addPost(args.authorId, args.title, args.content),
    addComment: (_, args) =>
      addComment(args.authorId, args.postId, args.content),
  },
  User: {
    posts: (parent: User) => getPostsByAuthor(parent.id),
    comments: (parent: User) => getCommentsByUser(parent.id),
  },
  Post: {
    abstract: (parent: Post) => getPostAbstract(parent),
    createdAt: (parent: Post) => parent.createdAt.toISOString(),
    author: (parent: Post) => getUserById(parent.authorId),
    comments: (parent: Post) => getCommentsByPost(parent.id),
  },
  Comment: {
    createdAt: (parent: Comment) => parent.createdAt.toISOString(),
    author: (parent: Comment) => getUserById(parent.authorId),
  },
}

export default resolvers
