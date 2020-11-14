# GraphQL Blog Demo

This is a demo showcasing a simple blog application backed by a GraphQL server.

## Getting started

### Server

- Navigate into the `server` directory
- Run `npm install`
- Run `npm start:watch`

This launches the GraphQL-server on port 5000.
Changes in the source files will automatically trigger a server restart.
**The server does not persist its data.
Upon restarting, the server data is reset to its initial state.**

### Client

- Navigate into the `client` directory
- Run `npm install`
- Run `npm start`

This launches a dev server which serves the app on port 1234.
Changes in the source files will update the UI in place (without page reload) if possible, otherwise the site will reload automatically.

`npm start` launches the Reason-compiler and the dev-webserver in one terminal process.
It is recommended to launch both in two different processes. For that run `npm run re:watch` for the Reason-compiler and `npm run parcel:serve` for the dev-webserver.

If the GraphQL schema on the server changes, you need to run `npm run update-schema`, so graphql-ppx can correctly typecheck all GraqhQL operations.

## Tech stack

### Client

- [ReasonML/ReScript](https://rescript-lang.org/)
- [React](https://reactjs.org)
- [ReasonReact](https://reasonml.github.io/reason-react/)
- [Apollo Client](https://www.apollographql.com/docs/react/)
- [Reason Apollo Client](https://github.com/reasonml-community/reason-apollo-client)
- [Graphql-ppx](https://graphql-ppx.com/)
- [Bulma](https://bulma.io/)

### Server

- [TypeScript](https://www.typescriptlang.org/)
- [Express](https://expressjs.com/).
- [Apollo Server](https://www.apollographql.com/docs/apollo-server/)

## VSCode-setup

Since the server uses the standard TypeScript-stack, no additional config is needed here.

For the client, install [reason-vscode](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode) for Reason-support and [vscode-reasonml-graphql](https://marketplace.visualstudio.com/items?itemName=GabrielNordeborn.vscode-reasonml-graphql) for GraphQl-support in Reason. Check their documentation for setup information.
