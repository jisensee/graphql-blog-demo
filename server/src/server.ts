import { ApolloServer } from 'apollo-server-express'
import cors from 'cors'
import express from 'express'
import schema from './schema'

const app = express()

const server = new ApolloServer({
  schema,
  playground: true,
})

app.use('*', cors())

server.applyMiddleware({ app, path: '/graphql' })

app.listen(5000, () => console.log('Server started on port 5000'))
