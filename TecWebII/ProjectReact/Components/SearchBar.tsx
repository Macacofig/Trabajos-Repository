type Props = {
  search: string;
  setSearch: (value: string) => void;
};

export default function SearchBar({ search, setSearch }: Props) {
  return (
    <input
      type="text"
      placeholder="Buscar país..."
      value={search}
      onChange={(e) => setSearch(e.target.value)}
    />
  );
}