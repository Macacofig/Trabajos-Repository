import { useEffect, useState } from 'react';
import type { Country } from './types/country';

import CountryCard from './Components/CountryCard';
import CountryDetail from './Components/CountryDetail';
import SearchBar from './Components/SearchBar';
import RegionFilter from './Components/RegionFilter';

import './App.css';

export default function App() {
  const [countries, setCountries] = useState<Country[]>([]);
  const [filtered, setFiltered] = useState<Country[]>([]);
  const [search, setSearch] = useState('');
  const [region, setRegion] = useState('Todos');
  const [sort, setSort] = useState('');
  const [selected, setSelected] = useState<Country | null>(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<Error | null>(null);

  useEffect(() => {
    fetch('https://restcountries.com/v3.1/all?fields=name,capital,region,population,flags,languages,currencies,timezones,maps')
      .then(res => res.json())
      .then((data: Country[]) => {
        setCountries(data);
        setFiltered(data);
        setLoading(false);
      })
      .catch(err => {
        setError(err);
        setLoading(false);
      });
  }, []);

  useEffect(() => {
    let result = [...countries];

    if (search) {
      result = result.filter(c =>
        c.name.common.toLowerCase().includes(search.toLowerCase())
      );
    }

    if (region !== 'Todos') {
      result = result.filter(c => c.region === region);
    }

    if (sort === 'asc') {
      result.sort((a, b) => a.population - b.population);
    } else if (sort === 'desc') {
      result.sort((a, b) => b.population - a.population);
    }

    setFiltered(result);
  }, [search, region, sort, countries]);

  if (loading) return <p className="container">Cargando...</p>;
  if (error) return <p className="container">Error al cargar datos</p>;

  if (selected) {
    return (
      <CountryDetail
        country={selected}
        onBack={() => setSelected(null)}
      />
    );
  }

  return (
    <div className="container">
      <h1 className="header">Países</h1>
      <p className="results">
        Resultados: {filtered.length} países
      </p>
      <div className="controls">
        <SearchBar search={search} setSearch={setSearch} />
        <RegionFilter region={region} setRegion={setRegion} />

        <select onChange={(e) => setSort(e.target.value)}>
          <option value="">Ordenar</option>
          <option value="asc">Población Mayor</option>
          <option value="desc">Población Menor</option>
        </select>
      </div>

      <div className="grid">
        {filtered.map((c, i) => (
          <CountryCard key={i} country={c} onClick={() => setSelected(c)} />
        ))}
      </div>
    </div>
  );
}