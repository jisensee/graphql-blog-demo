let instance =
  ApolloClient.(
    make(
      ~cache=Cache.InMemoryCache.make(),
      ~uri=_ => "http://localhost:5000/graphql",
      ~connectToDevTools=true,
      ~defaultOptions=
        DefaultOptions.make(
          ~mutate=
            DefaultMutateOptions.make(
              ~awaitRefetchQueries=true,
              ~errorPolicy=All,
              (),
            ),
          ~query=
            DefaultQueryOptions.make(
              ~fetchPolicy=NetworkOnly,
              ~errorPolicy=All,
              (),
            ),
          (),
        ),
      (),
    )
  );
